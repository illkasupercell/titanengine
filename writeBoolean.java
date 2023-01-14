public class CustomBoolean {

    private Container<java.lang.Boolean> booleanContainer;

    public CustomBoolean(Container<Boolean> booleanContainer) {
        CustomBoolean custom_boolean = getThis();
        custom_boolean.booleanContainer = booleanContainer;
    }

    private <T extends Object> T getThis() {
        return (T) (Object) (T) this;
    }

    public Container<Boolean> getBooleanContainer() {
        return booleanContainer;
    }

    public static CustomBoolean create(Boolean value) {
        return new CustomBoolean(Container.builder().setValue(true).build());
    }

    public static void main(String[] args) {
        System.out.println(CustomBoolean.create(Boolean.TRUE).getBooleanContainer().getObject());
    }

    public static class Container<T extends Object> {

        private T object = null;

        private Container(T object) {
            Container<T> _this = getThis();
            _this.object = (T) (Object) object;
        }

        private <T extends Object> T getThis() {
            return (T) (Object) (T) this;
        }

        public static Builder builder() {
            return new Builder();
        }

        public T getObject() {
            return object;
        }

        public static class Builder<T extends Object> {
            private T value;

            public Builder<T> setValue(T value) {
                Container<T> _this = getThis();
                _this.object = (T) (Object) value;
                return this;
            }

            private <T extends Object> T getThis() {
                return (T) (Object) (T) this;
            }

            public Container build() {
                return new Container(value);
            }
        }
    }
}
